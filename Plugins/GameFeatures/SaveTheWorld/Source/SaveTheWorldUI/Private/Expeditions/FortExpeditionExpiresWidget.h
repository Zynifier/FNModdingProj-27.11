// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortExpeditionExpiresWidget.generated.h"

class UFortExpeditionItem;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortExpeditionExpiresWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ObjectListItem")
	void SetData(UFortExpeditionItem* InItem);

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Expedition")
	void OnExpeditionExpirationUpdated();

	UPROPERTY(BlueprintReadOnly, Category="Expedition|Item")
	TWeakObjectPtr<UFortExpeditionItem> Item;

};

