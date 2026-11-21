// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/CobaltWidgetBase.h"
#include "Athena/Modifiers/FortAthenaMutator_Cobalt.h"
#include "CobaltRoundStartWidgetBase.generated.h"

class UCobaltPlayerPortraitWidget;

USTRUCT(BlueprintType)
struct FCobaltPlayerPortraitIndexInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CobaltPlayerPortraitIndexInfo")
	TArray<int32> PortraitIndexArray;

};

UCLASS()
class UCobaltRoundStartWidgetBase : public UCobaltWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleHideRoundStartWidget();

	UFUNCTION()
	void HandleShowRoundStartWidget(const FCobaltWidgetRoundData& RoundData);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleUpdateIntelInfo_BP(int32 CurrentRound, uint8 LastRoundWinningTeam);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleUpdateRoundStartWidgetVisibility_BP(bool bNewVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleUpdateVsInfo_BP(int32 CurrentActiveRound, const FText& RoundName, const FText& POIName);

	UPROPERTY(EditDefaultsOnly, Category="CobaltRoundStartWidgetBase")
	TArray<FCobaltPlayerPortraitIndexInfo> UpperBannerPortraitIndexInfos;

	UPROPERTY(EditDefaultsOnly, Category="CobaltRoundStartWidgetBase")
	TArray<FCobaltPlayerPortraitIndexInfo> LowerBannerPortraitIndexInfos;

	UPROPERTY(BlueprintReadWrite, Export, Category="CobaltRoundStartWidgetBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UCobaltPlayerPortraitWidget>> PlayerPortraits_Team1;

	UPROPERTY(BlueprintReadWrite, Export, Category="CobaltRoundStartWidgetBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UCobaltPlayerPortraitWidget>> PlayerPortraits_Team2;

};

