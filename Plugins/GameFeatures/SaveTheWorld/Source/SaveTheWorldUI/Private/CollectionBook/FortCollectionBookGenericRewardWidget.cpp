// Copyright Epic Games, Inc. All Rights Reserved.

#include "CollectionBook/FortCollectionBookGenericRewardWidget.h"

void UFortCollectionBookGenericRewardWidget::ClearRewards()
{
}

ECollectionBookRewardStatus UFortCollectionBookGenericRewardWidget::GetRewardStatus() const
{
	return ECollectionBookRewardStatus();
}

bool UFortCollectionBookGenericRewardWidget::HasRewards() const
{
	return false;
}

void UFortCollectionBookGenericRewardWidget::OnRewardStatusChanged_Implementation(ECollectionBookRewardStatus NewStatus)
{
}

void UFortCollectionBookGenericRewardWidget::SetCurrentItemToDisplay(UFortItem* ItemToDisplay)
{
}

void UFortCollectionBookGenericRewardWidget::SetRewards(const FFortRewardInfo& Rewards)
{
}

void UFortCollectionBookGenericRewardWidget::SetRewardStatus(ECollectionBookRewardStatus Status)
{
}
