/*
 * ScoreView.cpp
 *
 *  Created on: 06.02.2013
 *      Author: daniel
 */

#include "StateWidget.h"
#include <iostream>

namespace LLSFVis {

StateWidget::StateWidget() {

	set_orientation(Gtk::ORIENTATION_VERTICAL);

	scoreLabel_.set_justify(Gtk::JUSTIFY_CENTER);
	timeLabel_.set_justify(Gtk::JUSTIFY_CENTER);
	Pango::FontDescription font;
	font.set_size(Pango::SCALE * 28);
	font.set_weight(Pango::WEIGHT_BOLD);
	scoreLabel_.override_font(font);
	timeLabel_.override_font(font);

	gameStateLabel_.override_font(font);
	gameStateFrame_.set_label("Game State");
	scoreFrame_.set_label("Scores");
	timeFrame_.set_label("Game Time");

	timeFrame_.add(timeLabel_);
	scoreFrame_.add(scoreLabel_);
	gameStateFrame_.add(gameStateLabel_);

	pack_start(gameStateFrame_);
	pack_start(botStates_);
	pack_start(scoreFrame_, Gtk::PACK_EXPAND_WIDGET);
	pack_start(timeFrame_, Gtk::PACK_EXPAND_WIDGET);

	//default value:
	set_game_phase(llsf_msgs::GameState::INIT_GAME);

}

void StateWidget::set_score(int score) {
	std::ostringstream os;
	os << score;
	scoreLabel_.set_text(os.str());
}

std::string seconds_to_str(int sec) {
	int minutes = sec / 60;
	int seconds = sec % 60;
	std::ostringstream os;
	std::string sec_zeroes = "";
	std::string min_zeroes = "";
	if (seconds < 10) {
		sec_zeroes = "0";
	}
	if (minutes < 10) {
		min_zeroes = "0";
	}
	os << min_zeroes << minutes << ":" << sec_zeroes << seconds;
	return os.str();
}

void StateWidget::set_time(const llsf_msgs::Time& time) {
	timeLabel_.set_text(seconds_to_str(time.sec()));
}

StateWidget::~StateWidget() {
	// TODO Auto-generated destructor stub
}

void StateWidget::set_game_phase(llsf_msgs::GameState::State state) {
	Glib::ustring label;
	switch (state) {
	case llsf_msgs::GameState::INIT_GAME:
		label = "Preparation";
		break;
	case llsf_msgs::GameState::EXPLORATION:
		label = "Exploration";
		break;
	case llsf_msgs::GameState::PRODUCTION:
		label = "Production";
		break;
	case llsf_msgs::GameState::GAME_END:
		label = "Game Over";
		break;
	case llsf_msgs::GameState::PAUSE:
		label = "Game Paused";
		break;
	default:
		break;
	}
	gameStateLabel_.set_text(label);
}

void StateWidget::update_game_state(llsf_msgs::GameState& gameState) {
	set_game_phase(gameState.state());
	set_time(gameState.timestamp());
	set_score(gameState.points());

}

void StateWidget::update_robot_info(llsf_msgs::RobotInfo& robotInfo) {

		switch (robotInfo.robots_size()) {
		case 3:
			botStates_.setBot3(robotInfo.robots(2));
		case 2:
			botStates_.setBot3(robotInfo.robots(1));
		case 1:
			botStates_.setBot3(robotInfo.robots(0));
			break;
		default:
			botStates_.clear();
		}
}

} /* namespace LLSFVis */
