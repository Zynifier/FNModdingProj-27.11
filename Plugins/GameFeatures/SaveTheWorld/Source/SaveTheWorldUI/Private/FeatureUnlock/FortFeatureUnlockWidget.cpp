// Copyright Epic Games, Inc. All Rights Reserved.

#include "FeatureUnlock/FortFeatureUnlockWidget.h"

FText UFortFeatureUnlockWidget::GetDescription() const
{
	return FText();
}

TSoftObjectPtr<UTexture2D> UFortFeatureUnlockWidget::GetLargeIcon() const
{
	return TSoftObjectPtr<UTexture2D>();
}

TSoftObjectPtr<UTexture2D> UFortFeatureUnlockWidget::GetSmallIcon() const
{
	return TSoftObjectPtr<UTexture2D>();
}

FText UFortFeatureUnlockWidget::GetTitle() const
{
	return FText();
}

UMediaSource* UFortFeatureUnlockWidget::GetVideo() const
{
	return nullptr;
}

void UFortFeatureUnlockWidget::SetData(const FString& ItemTemplateId)
{
}
