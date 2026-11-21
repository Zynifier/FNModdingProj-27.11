// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigameScoring.h"
#include "Net/UnrealNetwork.h"

bool AFortMinigameScoreRegistry::GetHighScores(TArray<FMinigameScoreEntry>& HighScores) const
{
	return false;
}

bool AFortMinigameScoreRegistry::GetScores(AFortPlayerState* PlayerState, TArray<FMinigameScoreEntry>& ScoreEnties) const
{
	return false;
}

void AFortMinigameScoreRegistry::OnRep_Playset()
{
}

void AFortMinigameScoreRegistry::OnRep_Scores()
{
}

FText AFortMinigameScoreRegistry::PointsToText(float Points)
{
	return FText();
}

bool AFortMinigameScoreRegistry::RecordScore(AFortPlayerState* PlayerState, float Score)
{
	return false;
}

bool AFortMinigameScoreRegistry::RemoveAllScores(AFortPlayerState* PlayerState)
{
	return false;
}

FText AFortMinigameScoreRegistry::ScoreToText_Implementation(float Score) const
{
	return FText();
}

FText AFortMinigameScoreRegistry::TimeToText(float Time)
{
	return FText();
}

void AFortMinigameScoreRegistry::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMinigameScoreRegistry, Playset);
	DOREPLIFETIME(AFortMinigameScoreRegistry, ScoreTemplate);
	DOREPLIFETIME(AFortMinigameScoreRegistry, Scores);
}
