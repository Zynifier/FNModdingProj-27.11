// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/QuestEditor/QuestEditorButton.h"
#include "QuestTabButton.generated.h"

class UQuestUnsavedChangesIndicator;

UCLASS(Abstract, meta=(DisableNativeTick))
class UQuestTabButton : public UQuestEditorButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RemoveQuestAssetTab();

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UQuestUnsavedChangesIndicator> Image_UnsavedChangesIndicator;

};

