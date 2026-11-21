// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIStateChartEditorTransitionOptionsMenu.generated.h"

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorTransitionOptionsMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UUIStateChartEditorTransitionOptionsMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintCallable)
	void HandleDeleteClicked();

	UFUNCTION(BlueprintCallable)
	void HandleEditClicked();

};

