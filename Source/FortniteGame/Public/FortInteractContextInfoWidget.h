// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortInteractContextInfoWidget.generated.h"

class UFortInteractContextInfo;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortInteractContextInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortInteractContextInfoWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GetInteractText(FText& InteractText, bool& Result);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool GetShowErrorsUsingDefaultWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void OnContextInfoUpdated(const UFortInteractContextInfo* ContextInfo);

};

