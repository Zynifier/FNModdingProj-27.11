// Copyright Epic Games, Inc. All Rights Reserved.

#include "Research/FortResearchStatTileWidget.h"

UFortResearchStatTileWidget::UFortResearchStatTileWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

int32 UFortResearchStatTileWidget::GetCostToIncreaseStat() const
{
	return int32();
}

int32 UFortResearchStatTileWidget::GetCurrentCombinedStatValue() const
{
	return int32();
}

int32 UFortResearchStatTileWidget::GetCurrentPersonalStatValue() const
{
	return int32();
}

int32 UFortResearchStatTileWidget::GetCurrentResearchLevel() const
{
	return int32();
}

int32 UFortResearchStatTileWidget::GetCurrentTeamStatValue() const
{
	return int32();
}

int32 UFortResearchStatTileWidget::GetNextCombinedStatValueDelta() const
{
	return int32();
}

int32 UFortResearchStatTileWidget::GetNextPersonalStatValueDelta() const
{
	return int32();
}

int32 UFortResearchStatTileWidget::GetNextTeamStatValueDelta() const
{
	return int32();
}

EFortStatType UFortResearchStatTileWidget::GetPersonalStatType() const
{
	return EFortStatType();
}

const FString UFortResearchStatTileWidget::GetStatIdName() const
{
	return FString();
}

bool UFortResearchStatTileWidget::IsAtMaxResearchLevel() const
{
	return false;
}
