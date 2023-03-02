const { SlashCommandBuilder } = require('discord.js');

module.exports = {
    data: new SlashCommandBuilder()
        .setName('setactivity')
        .setDescription('Sets the bot\'s activity')

        .addStringOption(option =>
            option.setName('activity')
                .setDescription('The activity to set')
                .setRequired(true)),
    async execute(interaction) {
        const activity = interaction.options.getString('activity');
        await interaction.client.user.setActivity(activity);
        await interaction.reply(`Set activity to ${activity}`);
    },
};
