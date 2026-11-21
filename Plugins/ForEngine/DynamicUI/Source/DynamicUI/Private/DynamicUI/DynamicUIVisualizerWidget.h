// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DynamicUIVisualizerWidget.generated.h"

class UDynamicUIScene;

UCLASS(meta=(ShortTooltip="Widget used to visualize Dynamic UI scenes. Cannot be compiled because it is only meant as a temporary hack to visualize the Dynamic UI scenes until a proper editor is made."))
class UDynamicUIVisualizerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UDynamicUIVisualizerWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Transient, Category="Dynamic UI")
	TArray<TObjectPtr<UDynamicUIScene>> Scenes;

	UPROPERTY(EditAnywhere, Transient, Category="Dynamic UI")
	bool bRefresh;

};

