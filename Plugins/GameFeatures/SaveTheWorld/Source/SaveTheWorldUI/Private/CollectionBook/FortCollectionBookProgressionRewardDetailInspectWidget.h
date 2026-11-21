// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCollectionBookProgressionRewardDetailInspectWidget.generated.h"

class UCommonNumericTextBlock;
class UFortRewardInfoWidget_Legacy;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookProgressionRewardDetailInspectWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CollectionBook")
	int32 GetXPRequired() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnXPRequiredChanged(int32 NewXPRequired);

	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	void SetAssociatedLevel(int32 Level);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> LevelTextWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRewardInfoWidget_Legacy> RewardWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> CheckmarkImage;

};

