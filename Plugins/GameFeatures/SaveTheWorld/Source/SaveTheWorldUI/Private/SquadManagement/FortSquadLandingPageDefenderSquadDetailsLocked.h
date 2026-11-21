// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SquadManagement/FortSquadLandingPageDefenderSummary.h"
#include "FortSquadLandingPageDefenderSquadDetailsLocked.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadLandingPageDefenderSquadDetailsLocked : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="SquadSummary")
	void SetDefenderSquadInfo(const FFortLandingPageDefenderSummaryInfo& DefenderSummaryInfo);

	UPROPERTY(BlueprintReadOnly, Export, Category="SquadSummary", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> OutpostName;

};

