// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortItemQuantityPair.h"
#include "FortItemBaseWidget.generated.h"

class UFortItemDefinition;

UCLASS(meta=(Category="Fortnite UI", DisableNativeTick))
class UFortItemBaseWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortItemBaseWidget")
	void SetItemDefinitionToRepresent(UFortItemDefinition* InItemDefinition);

	UFUNCTION(BlueprintCallable, Category="FortItemBaseWidget")
	bool SetItemQuantityPairToRepresent(FFortItemQuantityPair InItemQuantityPair);

protected:
	UFUNCTION(BlueprintPure, Category="FortItemBaseWidget")
	UFortItemDefinition* GetItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="FortItemBaseWidget")
	int32 GetQuantity() const;

	UFUNCTION(BlueprintPure, Category="FortItemBaseWidget")
	FText GetRichDescription() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortItemBaseWidget")
	void OnItemCountChanged(int32 NewCount);

	UFUNCTION(BlueprintImplementableEvent, Category="FortItemBaseWidget")
	void OnItemDefinitionChanged();

private:
	UFUNCTION()
	void HandleItemCountChanged(UFortItemDefinition* Definition, int32 Delta);

	UPROPERTY()
	FFortItemQuantityPair ItemQuantityPair;

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> ItemDefinition;

};

