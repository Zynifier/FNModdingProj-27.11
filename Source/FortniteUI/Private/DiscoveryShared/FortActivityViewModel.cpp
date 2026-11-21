// Copyright Epic Games, Inc. All Rights Reserved.

#include "DiscoveryShared/FortActivityViewModel.h"

bool UFortActivityViewModel::DoesActivityRequirePurchase() const
{
	return false;
}

EFortActivityIsLockedReason UFortActivityViewModel::GetActivityLockedReason() const
{
	return EFortActivityIsLockedReason();
}

const FText UFortActivityViewModel::GetAgeRatingShortText() const
{
	return FText();
}

const FText UFortActivityViewModel::GetAgeRatingText() const
{
	return FText();
}

UTexture2DDynamic* UFortActivityViewModel::GetAgeRatingTexture() const
{
	return nullptr;
}

int32 UFortActivityViewModel::GetCCUCount() const
{
	return int32();
}

FText UFortActivityViewModel::GetDescription() const
{
	return FText();
}

FText UFortActivityViewModel::GetDisplayName() const
{
	return FText();
}

FText UFortActivityViewModel::GetDisplaySubName() const
{
	return FText();
}

EActivityImageLoadingState UFortActivityViewModel::GetImageLoadingState() const
{
	return EActivityImageLoadingState();
}

UTexture* UFortActivityViewModel::GetImageTexture() const
{
	return nullptr;
}

FString UFortActivityViewModel::GetIslandCreatorName() const
{
	return FString();
}

int32 UFortActivityViewModel::GetMaxPlayersRangeMax() const
{
	return int32();
}

int32 UFortActivityViewModel::GetMaxPlayersRangeMin() const
{
	return int32();
}

int32 UFortActivityViewModel::GetMaxTeamSize() const
{
	return int32();
}

int32 UFortActivityViewModel::GetNumFriendsPlaying() const
{
	return int32();
}

ERatingsBoard UFortActivityViewModel::GetRatingBoard() const
{
	return ERatingsBoard();
}

const TArray<FText> UFortActivityViewModel::GetRatingDescriptors() const
{
	return TArray<FText>();
}

const TArray<FText> UFortActivityViewModel::GetRatingInteractiveElements() const
{
	return TArray<FText>();
}

FName UFortActivityViewModel::GetReferencePanelName() const
{
	return FName();
}

FName UFortActivityViewModel::GetReferenceSurfaceName() const
{
	return FName();
}

int32 UFortActivityViewModel::GetTeamSizeRangeMax() const
{
	return int32();
}

int32 UFortActivityViewModel::GetTeamSizeRangeMin() const
{
	return int32();
}

const bool UFortActivityViewModel::HasAgeRating() const
{
	return bool();
}

bool UFortActivityViewModel::IsActivityLocked() const
{
	return false;
}

bool UFortActivityViewModel::IsAgeRatingTextureRectangular() const
{
	return false;
}

bool UFortActivityViewModel::IsEpicCreated() const
{
	return false;
}

bool UFortActivityViewModel::IsEpicLabsCreated() const
{
	return false;
}

bool UFortActivityViewModel::IsEpicOriginalCreated() const
{
	return false;
}

bool UFortActivityViewModel::IsFavorite() const
{
	return false;
}

const bool UFortActivityViewModel::IsRatingNotApplicable() const
{
	return bool();
}

const bool UFortActivityViewModel::IsRatingRefused() const
{
	return bool();
}

void UFortActivityViewModel::ResetAnalytics()
{
}

void UFortActivityViewModel::StartActiveImpression()
{
}

void UFortActivityViewModel::StartVisibilityImpression()
{
}

void UFortActivityViewModel::StopActiveImpression()
{
}

void UFortActivityViewModel::StopVisibilityImpression()
{
}
