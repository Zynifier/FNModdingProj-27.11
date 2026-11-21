// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "EditorQuestToolUtilityWidget.generated.h"

class UObject;

UCLASS()
class UEditorQuestToolUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Asset Object Set"))
	void BP_OnAssetObjectSet();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnAssetUndoRedo();

	UFUNCTION(BlueprintImplementableEvent)
	void OnAssetPropertyChanged(const FName& PropertyName);

	UFUNCTION(BlueprintCallable)
	void SetAssetObject(UObject* InAssetObject);

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="EditorQuestToolUtilityWidget")
	TObjectPtr<UObject> AssetObject;

};

