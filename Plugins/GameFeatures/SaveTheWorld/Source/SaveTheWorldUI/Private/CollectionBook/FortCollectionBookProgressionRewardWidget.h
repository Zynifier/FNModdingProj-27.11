// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CollectionBook/FortCollectionBookGenericRewardWidget.h"
#include "FortCollectionBookProgressionRewardWidget.generated.h"

class UCommonNumericTextBlock;
class UCommonTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCollectionBookProgressionRewardWidget : public UFortCollectionBookGenericRewardWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	void SetAssociatedLevel(int32 Level);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> LevelTextWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> DisplayNameWidget;

};

