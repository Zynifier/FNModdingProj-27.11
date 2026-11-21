// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SquadManagement/FortSquadLandingPageDefenderSummary.h"
#include "FortSquadLandingPageDefenderSquadDetails.generated.h"

class UCommonNumericTextBlock;
class UCommonTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadLandingPageDefenderSquadDetails : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="SquadSummary")
	void HandleAddDefenderSquadMemberBP(const FName& SquadId, int32 Index);

	UFUNCTION(BlueprintImplementableEvent, Category="SquadSummary")
	void HandleDefenderSquadInfoSetBP(const FFortLandingPageDefenderSummaryInfo& DefenderSummaryInfo);

	UFUNCTION(BlueprintCallable, Category="SquadSummary")
	void SetDefenderSquadInfo(const FFortLandingPageDefenderSummaryInfo& DefenderSummaryInfo);

	UPROPERTY(BlueprintReadOnly, Export, Category="SquadSummary", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> OutpostName;

	UPROPERTY(BlueprintReadOnly, Export, Category="SquadSummary", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> PowerRating;

};

