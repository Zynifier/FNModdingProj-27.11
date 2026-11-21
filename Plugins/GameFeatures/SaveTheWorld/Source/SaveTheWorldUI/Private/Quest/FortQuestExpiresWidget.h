// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortQuestExpiresWidget.generated.h"

class UFortQuestItem;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestExpiresWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ObjectListItem")
	void SetData(UFortQuestItem* InItem);

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Quest")
	void OnQuestExpirationUpdated();

	UPROPERTY(BlueprintReadOnly, Category="Quest|Item")
	TWeakObjectPtr<UFortQuestItem> Item;

};

