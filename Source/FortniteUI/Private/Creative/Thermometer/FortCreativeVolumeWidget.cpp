// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Thermometer/FortCreativeVolumeWidget.h"

UFortCreativeVolumeWidget::UFortCreativeVolumeWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortCreativeVolumeWidget::BindToVolumeManager()
{
}

AFortVolume* UFortCreativeVolumeWidget::GetVolume() const
{
	return nullptr;
}

void UFortCreativeVolumeWidget::OnGameInstanceGameStateSet(AFortGameState* GameState)
{
}

void UFortCreativeVolumeWidget::OnVolumeManagerClientEnterVolume(APlayerState* PlayerState, AFortVolume* Volume)
{
}
