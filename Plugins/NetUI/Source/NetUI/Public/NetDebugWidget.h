// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NetDebugWidget.generated.h"

class UCommonTextBlock;

UCLASS(ClassGroup=("UI"), meta=(Category="Net UI", DisableNativeTick))
class NETUI_API UNetDebugWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UNetDebugWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintCallable, Category="Timer")
	void StartTimer();

	UFUNCTION(BlueprintCallable, Category="Timer")
	void StopTimer();

	UPROPERTY(BlueprintReadOnly, Export, Category="NetDebugWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PingUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="NetDebugWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PacketInRateUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="NetDebugWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PacketOutRateUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="NetDebugWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PacketInLossUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="NetDebugWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PacketOutLossUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="NetDebugWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> UpBandwidthUI;

	UPROPERTY(BlueprintReadOnly, Export, Category="NetDebugWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> DownBandwidthUI;

};

