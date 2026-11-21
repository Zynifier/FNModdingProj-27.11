// Copyright Epic Games, Inc. All Rights Reserved.

#include "DirectedAcquisition/FortDirectAcquisitionWidgetBase.h"

FDateTime UFortDirectAcquisitionWidgetBase::GetDailyStoreEndDate() const
{
	return FDateTime();
}

FDateTime UFortDirectAcquisitionWidgetBase::GetSeasonStoreEndDate() const
{
	return FDateTime();
}

TArray<UFortAccountItemDefinition*> UFortDirectAcquisitionWidgetBase::GetStoreCurrencies() const
{
	return TArray<UFortAccountItemDefinition*>();
}

FDateTime UFortDirectAcquisitionWidgetBase::GetWeeklyStoreEndDate() const
{
	return FDateTime();
}

void UFortDirectAcquisitionWidgetBase::HandleAffiliateButtonClicked()
{
}
