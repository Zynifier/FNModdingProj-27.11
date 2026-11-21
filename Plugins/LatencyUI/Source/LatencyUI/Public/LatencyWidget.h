// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LatencyWidget.generated.h"

class UCommonTextBlock;

UCLASS(ClassGroup=("UI"), meta=(Category="Net UI"))
class LATENCYUI_API ULatencyWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	ULatencyWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintCallable, Category="Timer")
	void StartTimer();

	UFUNCTION(BlueprintCallable, Category="Timer")
	void StopTimer();

	UPROPERTY(BlueprintReadOnly, Export, Category="LatencyWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TotalLatencyUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="LatencyWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> GameLatencyUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="LatencyWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> RenderLatencyUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="LatencyWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> OSWorkLatencyUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="LatencyWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> DriverLatencyUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="LatencyWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> GPURenderLatencyUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="LatencyWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TweakLatencyUI;

};

