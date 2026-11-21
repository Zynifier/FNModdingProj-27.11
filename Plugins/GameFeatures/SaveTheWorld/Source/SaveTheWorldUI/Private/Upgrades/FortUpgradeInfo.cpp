// Copyright Epic Games, Inc. All Rights Reserved.

#include "Upgrades/FortUpgradeInfo.h"

void UFortUpgradeInfo::BackwardPreview()
{
}

bool UFortUpgradeInfo::CanAffordUpgrade() const
{
	return false;
}

bool UFortUpgradeInfo::CanPreview() const
{
	return false;
}

void UFortUpgradeInfo::ForwardPreview()
{
}

int32 UFortUpgradeInfo::GetCost() const
{
	return int32();
}

int32 UFortUpgradeInfo::GetCurrentLevel() const
{
	return int32();
}

FText UFortUpgradeInfo::GetDescription() const
{
	return FText();
}

bool UFortUpgradeInfo::GetDisplayAttributes(TArray<FFortDisplayAttribute>& OutDisplayAttributes) const
{
	return false;
}

TSoftObjectPtr<UTexture2D> UFortUpgradeInfo::GetIcon(EUpgradeInfoImageSize ImageSize) const
{
	return TSoftObjectPtr<UTexture2D>();
}

FText UFortUpgradeInfo::GetItemName() const
{
	return FText();
}

int32 UFortUpgradeInfo::GetMaxLevel() const
{
	return int32();
}

int32 UFortUpgradeInfo::GetNextLevel() const
{
	return int32();
}

FText UFortUpgradeInfo::GetNextLevelDescription() const
{
	return FText();
}

FText UFortUpgradeInfo::GetNextLevelTitle() const
{
	return FText();
}

FText UFortUpgradeInfo::GetTitle() const
{
	return FText();
}

int32 UFortUpgradeInfo::GetUpgradeUnlockLevel() const
{
	return int32();
}

UMediaSource* UFortUpgradeInfo::GetVideo() const
{
	return nullptr;
}

bool UFortUpgradeInfo::IsPreviewing() const
{
	return false;
}

bool UFortUpgradeInfo::IsUpgradeUnlocked() const
{
	return false;
}
