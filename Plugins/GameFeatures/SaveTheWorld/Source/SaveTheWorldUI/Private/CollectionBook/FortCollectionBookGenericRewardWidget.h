// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "FortTypes.h"
#include "FortCollectionBookGenericRewardWidget.generated.h"

class UFortCollectionBookRewardCardWidget;
class UFortItem;
enum class ECollectionBookRewardStatus : uint8;

UENUM(BlueprintType)
enum class ECollectionBookRewardStatus : uint8
{
	Unknown = 0,
	Available = 1,
	Claimed = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookGenericRewardWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	virtual void ClearRewards();

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	virtual ECollectionBookRewardStatus GetRewardStatus() const;

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	virtual bool HasRewards() const;

	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	virtual void SetRewards(const FFortRewardInfo& Rewards);

	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	virtual void SetRewardStatus(ECollectionBookRewardStatus Status);

protected:
	UFUNCTION(BlueprintNativeEvent, Category="CollectionBook")
	void OnRewardStatusChanged(ECollectionBookRewardStatus NewStatus);

	UFUNCTION()
	virtual void SetCurrentItemToDisplay(UFortItem* ItemToDisplay);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collection Book")
	uint8 bUpdateVisibilityBasedOnRewardExistence : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collection Book", meta=(EditCondition="bUpdateVisibilityBasedOnRewardExistence"))
	ESlateVisibility VisibilityWhenNoRewardSpecified;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collection Book", meta=(EditCondition="bUpdateVisibilityBasedOnRewardExistence"))
	ESlateVisibility VisibilityWhenRewardSpecified;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookRewardCardWidget> RewardCardWidget;

	UPROPERTY(Transient)
	ECollectionBookRewardStatus RewardStatus;

};

