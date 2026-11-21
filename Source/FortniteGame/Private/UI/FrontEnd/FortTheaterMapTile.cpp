// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/FrontEnd/FortTheaterMapTile.h"

bool AFortTheaterMapTile::DoesTileAllowQuickplay() const
{
	return false;
}

FName AFortTheaterMapTile::GetMissionAlertCategoryName() const
{
	return FName();
}

FGameplayTagContainer AFortTheaterMapTile::GetMissionAlertVisualTags() const
{
	return FGameplayTagContainer();
}

int32 AFortTheaterMapTile::GetMissionContentDifficultyLevel() const
{
	return int32();
}

bool AFortTheaterMapTile::GetMissionDefinitionIcon(FSlateBrush& OutMissionDefIcon) const
{
	return false;
}

FGameDifficultyInfo AFortTheaterMapTile::GetZoneDifficulty() const
{
	return FGameDifficultyInfo();
}

bool AFortTheaterMapTile::HasValidMissionData() const
{
	return false;
}

bool AFortTheaterMapTile::IsMissionAlertTile() const
{
	return false;
}

bool AFortTheaterMapTile::IsTeamRatingDataValid() const
{
	return false;
}

bool AFortTheaterMapTile::IsTileHidden() const
{
	return false;
}

bool AFortTheaterMapTile::IsTileInPhoenixTheater() const
{
	return false;
}

bool AFortTheaterMapTile::IsTileLocked() const
{
	return false;
}

bool AFortTheaterMapTile::IsTilePlayable() const
{
	return false;
}

bool AFortTheaterMapTile::IsTileQuestRecommended() const
{
	return false;
}

bool AFortTheaterMapTile::IsTileSelectable() const
{
	return false;
}

bool AFortTheaterMapTile::IsTileValidForMarkedQuest(UFortQuestItem*& OutMarkedQuest) const
{
	return false;
}

void AFortTheaterMapTile::OnDeselectWrapper(bool bIsGameSessionOwner)
{
}

void AFortTheaterMapTile::OnMouseOverBegin(AActor* MousedOverActor)
{
}

void AFortTheaterMapTile::OnMouseOverEnd(AActor* MousedOverActor)
{
}

void AFortTheaterMapTile::OnSelectWrapper(bool bIsGameSessionOwner)
{
}

void AFortTheaterMapTile::OnTileClicked(AActor* ClickedActor, FKey ButtonReleased)
{
}
