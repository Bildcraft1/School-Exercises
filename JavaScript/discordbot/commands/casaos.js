const { SlashCommandBuilder } = require('discord.js');

module.exports = {
    data: new SlashCommandBuilder()
        .setName('casaos')
        .setDescription('Provides information about the CasaOS.'),

    async execute(interaction) {
        await interaction.reply('**CasaOS** installed in this discord server.\n http://demo.casaos.io/#/login\n Username: demo\n Password: demo \n Command line: `curl -fsSL https://get.casaos.io | sudo bash`');
        console.log('CasaOS command executed by ' + interaction.user.username + '#' + interaction.user.discriminator);
    },
};