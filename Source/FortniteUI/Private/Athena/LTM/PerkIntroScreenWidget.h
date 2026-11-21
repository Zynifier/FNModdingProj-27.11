// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/SpyTechPerkSystemPlayerControllerComponent.h"
#include "PerkIntroScreenWidget.generated.h"

class UFortAccoladeItemDefinition;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPerkIntroFinished);

USTRUCT(BlueprintType)
struct FPerkPipData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PerkPipData")
	TObjectPtr<UFortAccoladeItemDefinition> AccoladeItemDef;

	UPROPERTY(BlueprintReadOnly, Category="PerkPipData")
	int32 NumOfPips;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UPerkIntroScreenWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void GatherPerkPipData();

	UFUNCTION(BlueprintCallable)
	void PerkIntroFinished();

	UFUNCTION(BlueprintCallable)
	virtual void StartPerkScreenIntro();

	UPROPERTY(BlueprintAssignable)
	FOnPerkIntroFinished OnPerkIntroFinishedEvent;

	UPROPERTY(BlueprintReadOnly, Category="PerkIntroScreenWidget")
	TArray<FPerkPipData> PreviousPerkPipData;

	UPROPERTY(BlueprintReadOnly, Category="PerkIntroScreenWidget")
	TArray<FPerkPipData> NewPerkPipData;

	UPROPERTY(BlueprintReadOnly, Category="PerkIntroScreenWidget")
	TArray<FPerkPipData> PerkPipData;

	UPROPERTY(BlueprintReadOnly, Category="PerkIntroScreenWidget")
	FRoundTechDataCache StartRoundCache;

	UPROPERTY(BlueprintReadOnly, Category="PerkIntroScreenWidget")
	FGameplayTag FactionTag;

};

