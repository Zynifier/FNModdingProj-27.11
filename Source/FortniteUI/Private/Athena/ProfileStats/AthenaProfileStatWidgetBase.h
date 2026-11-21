// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "AthenaProfileStatWidgetBase.generated.h"

class UAthenaBaseStatView;
class UAthenaProfileStatBox;

USTRUCT(BlueprintType)
struct FStatGroupData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatGroupData")
	FText GroupName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatGroupData")
	FSlateBrush Group;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatGroupData")
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatGroupData")
	float ChartValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatGroupData")
	float ChartOrigionalValue;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaProfileStatWidgetBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AthenaProfileStatWidgetBase")
	TArray<FStatGroupData> CreateWeaponGroupData(int32 MaxToReturn = 5, bool bIncludeOtherCategory = true, bool bPercentages = true);

	UFUNCTION(BlueprintCallable, Category="AthenaProfileStatWidgetBase")
	void SetAsStat(const FGameplayTag& InStat);

	UFUNCTION(BlueprintCallable, Category="AthenaProfileStatWidgetBase")
	void SetStatView(UAthenaBaseStatView* InStatView, bool RespectParentStatView = false);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="AthenaProfileStatWidgetBase")
	void OnStatChanged();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaProfileStatWidgetBase", meta=(Categories="GameplayStat.Profile"))
	FGameplayTag Stat;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaProfileStatWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaProfileStatBox> ProfileStatBox;

private:
	UFUNCTION()
	void HandleStatViewChanged(UAthenaBaseStatView* StatView);

};

