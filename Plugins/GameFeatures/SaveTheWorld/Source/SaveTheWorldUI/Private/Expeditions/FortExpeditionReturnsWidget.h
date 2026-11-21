// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortExpeditionReturnsWidget.generated.h"

class UFortExpeditionItem;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortExpeditionReturnsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ObjectListItem")
	void SetData(UFortExpeditionItem* InItem);

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Expedition")
	void OnExpeditionInProgressUpdated();

	UPROPERTY(BlueprintReadOnly, Category="Expedition|Item")
	TWeakObjectPtr<UFortExpeditionItem> Item;

};

