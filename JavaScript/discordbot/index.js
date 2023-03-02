// Require the necessary discord.js classes
const { Client, Events, GatewayIntentBits, Collection, Partials } = require('discord.js');
const { token, guild_id } = require('./config.json');
const fs = require('node:fs');
const path = require('node:path');
var figlet = require('figlet');

figlet('Skins2', function(err, data) {
    if (err) {
        console.log('Something went wrong...');
        console.dir(err);
        return;
    }
    console.log(data)
});

// Create a new client instance
const client = new Client({
	intents: [
		GatewayIntentBits.GuildMembers,
		GatewayIntentBits.MessageContent,
		GatewayIntentBits.GuildMessages,
		GatewayIntentBits.Guilds,
		GatewayIntentBits.GuildMessageReactions,
		GatewayIntentBits.GuildWebhooks,
		GatewayIntentBits.GuildIntegrations,
		GatewayIntentBits.GuildVoiceStates,
		GatewayIntentBits.DirectMessages,
		GatewayIntentBits.GuildInvites,
		GatewayIntentBits.GuildPresences,
	],
	partials: [
		Partials.Channel,
		Partials.GuildMember,
		Partials.Message,
		Partials.Reaction,
		Partials.User,
		Partials.GuildScheduledEvent,
		Partials.ThreadMember,
	],
});

client.commands = new Collection();

const commandsPath = path.join(__dirname, 'commands');
const commandFiles = fs.readdirSync(commandsPath).filter(file => file.endsWith('.js'));

const commandsArray = [];

// Loop over the files in the commands folder and subfolders
for (const file of commandFiles) {
	const filePath = path.join(commandsPath, file);
	const command = require(filePath);
	// Get the command data from the file
	if ('data' in command && 'execute' in command) {
		client.commands.set(command.data.name, command);
		commandsArray.push(command.data.toJSON());
		console.log(`[INFO] Loaded command ${command.data.name}`);
	} else {
		console.log(`[WARNING] The command at ${filePath} is missing a required "data" or "execute" property.`);
	}
}

// When the client is ready, run this code (only once)
// We use 'c' for the event parameter to keep it separate from the already defined 'client'
client.on(Events.ClientReady, c => {
	console.log(`Ready! Logged in as ${c.user.tag}`);
	c.guilds.cache.get(guild_id).commands.set(commandsArray);
	// Set the client user's activity
	c.user.setActivity('with Discord.js');
});

client.on(Events.InteractionCreate, async interaction => {
	if (!interaction.isChatInputCommand()) return;

	const command = interaction.client.commands.get(interaction.commandName);

	if (!command) {
		console.error(`No command matching ${interaction.commandName} was found.`);
		return;
	}

	try {
		await command.execute(interaction);
	} catch (error) {
		console.error(error);
		if (interaction.replied || interaction.deferred) {
			await interaction.followUp({ content: 'There was an error while executing this command!', ephemeral: true });
		} else {
			await interaction.reply({ content: 'There was an error while executing this command!', ephemeral: true });
		}
	}
});

// Log in to Discord with your client's token
client.login(token);