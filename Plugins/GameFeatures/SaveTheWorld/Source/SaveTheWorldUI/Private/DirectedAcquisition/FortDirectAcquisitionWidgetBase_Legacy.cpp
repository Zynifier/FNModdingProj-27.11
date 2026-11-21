// Copyright Epic Games, Inc. All Rights Reserved.

#include "DirectedAcquisition/FortDirectAcquisitionWidgetBase_Legacy.h"

FDateTime UFortDirectAcquisitionWidgetBase_Legacy::GetDailyStoreEndDate() const
{
	return FDateTime();
}

FDateTime UFortDirectAcquisitionWidgetBase_Legacy::GetSeasonStoreEndDate() const
{
	return FDateTime();
}

TArray<UFortAccountItemDefinition*> UFortDirectAcquisitionWidgetBase_Legacy::GetStoreCurrencies() const
{
	return TArray<UFortAccountItemDefinition*>();
}

FDateTime UFortDirectAcquisitionWidgetBase_Legacy::GetWeeklyStoreEndDate() const
{
	return FDateTime();
}

void UFortDirectAcquisitionWidgetBase_Legacy::HandleAffiliateButtonClicked()
{
}
