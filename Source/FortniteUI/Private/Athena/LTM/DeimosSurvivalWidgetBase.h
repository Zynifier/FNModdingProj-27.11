// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortHUDElementWidget.h"
#include "DeimosSurvivalWidgetBase.generated.h"

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class ESurvivalObjectiveIconState : uint8
{
	None = 0,
	Spawned = 1,
	Destroyed = 2,
};

USTRUCT(BlueprintType)
struct FSurvivalObjectiveIconData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SurvivalObjectiveIconData")
	int32 IconIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SurvivalObjectiveIconData")
	ESurvivalObjectiveIconState IconState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SurvivalObjectiveIconData")
	ESurvivalObjectiveIconState PrevIconState;

	UPROPERTY(Transient)
	FName SpecialActorID;

};

USTRUCT(BlueprintType)
struct FSurvivalObjectiveText
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SurvivalObjectiveText")
	TArray<FString> SafezoneStateText;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UDeimosSurvivalWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateObjectiveIcon(const FSurvivalObjectiveIconData& ObjectiveIconData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateStateText(const FText& StateText);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Objectives Text", meta=(AllowPrivateAccess="true"))
	TArray<FSurvivalObjectiveText> SurvivalStateDefaultText;

	UPROPERTY(Transient)
	FGameplayTag ObjectiveTag;

};

