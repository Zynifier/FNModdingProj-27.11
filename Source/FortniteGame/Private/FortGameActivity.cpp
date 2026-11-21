// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameActivity.h"

TArray<FCreativeIslandDescriptionTag> UFortGameActivity::GetActivityDescriptionTags() const
{
	return TArray<FCreativeIslandDescriptionTag>();
}

const FText UFortGameActivity::GetAgeRatingShortText() const
{
	return FText();
}

const FText UFortGameActivity::GetAgeRatingText() const
{
	return FText();
}

UTexture2DDynamic* UFortGameActivity::GetAgeRatingTexture() const
{
	return nullptr;
}

bool UFortGameActivity::GetIsFavorite() const
{
	return false;
}

EFortActivityIsLockedReason UFortGameActivity::GetIsLockedReason() const
{
	return EFortActivityIsLockedReason();
}

const FString UFortGameActivity::GetPreviewPath(const ECreativeLinkPreviewSize PreviewSize) const
{
	return FString();
}

const ERatingsBoard UFortGameActivity::GetRatingBoard() const
{
	return ERatingsBoard();
}

const TArray<FText> UFortGameActivity::GetRatingDescriptors() const
{
	return TArray<FText>();
}

const TArray<FText> UFortGameActivity::GetRatingInteractiveElements() const
{
	return TArray<FText>();
}

const bool UFortGameActivity::HasAgeRating() const
{
	return bool();
}

bool UFortGameActivity::IsAgeRatingTextureRectangular() const
{
	return false;
}

bool UFortGameActivity::IsLocked() const
{
	return false;
}

const bool UFortGameActivity::IsRatingNotApplicable() const
{
	return bool();
}

const bool UFortGameActivity::IsRatingRefused() const
{
	return bool();
}
