const { SlashCommandBuilder } = require('discord.js');

module.exports = {
    data: new SlashCommandBuilder()
        .setName('setstatus')
        .setDescription('Sets the bot\'s status')
        .addStringOption(option =>
            option.setName('status')
                .setDescription('The status to set')
                .setRequired(true)),
    async execute(interaction) {
        const status = interaction.options.getString('status');
        await interaction.client.user.setStatus(status);
        await interaction.reply(`Set status to ${status}`);
    },
};
