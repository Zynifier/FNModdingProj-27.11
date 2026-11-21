// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "UIStateChartEditorStateFilterMenuItem.generated.h"

class UTextBlock;

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorStateFilterMenuItem : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UUIStateChartEditorStateFilterMenuItem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorStateFilterMenuItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> StateNameTextBlock;

};

