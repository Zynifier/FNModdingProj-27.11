// Copyright Epic Games, Inc. All Rights Reserved.

#include "MOTD/FortAthenaMOTDWidget.h"

bool UFortAthenaMOTDWidget::AutoPlayedVideo() const
{
	return false;
}

FAthenaMOTDBase UFortAthenaMOTDWidget::BP_GetSelectedNews() const
{
	return FAthenaMOTDBase();
}

FAthenaMOTDBase UFortAthenaMOTDWidget::GetNewsByIndex(int32 Index) const
{
	return FAthenaMOTDBase();
}

int32 UFortAthenaMOTDWidget::GetNewsCount() const
{
	return int32();
}

void UFortAthenaMOTDWidget::HandleImageLoaded()
{
}

void UFortAthenaMOTDWidget::HandleSelectedButtonChanged(UCommonButtonLegacy* SelectedButton, int32 ButtonIndex)
{
}

void UFortAthenaMOTDWidget::NavigateToLeftNews()
{
}

void UFortAthenaMOTDWidget::NavigateToRightNews()
{
}

bool UFortAthenaMOTDWidget::PlayFirstAutoPlayVideo()
{
	return false;
}

void UFortAthenaMOTDWidget::SelectNewsByIndex(int32 Index)
{
}
