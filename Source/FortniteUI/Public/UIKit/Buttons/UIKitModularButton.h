// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "UIKit/Blocks/UIKitBlock.h"
#include "UIKitModularButton.generated.h"

class UUIKitBlock;
enum class EUIKitBlockInstantTransitionState : uint8;
enum class EUIKitBlockVisualState : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UUIKitModularButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RegisterModularBlock(UUIKitBlock* Block);

	UFUNCTION(BlueprintCallable)
	void RequestInstantTransitionOnBlocks(EUIKitBlockInstantTransitionState State);

	UFUNCTION(BlueprintCallable)
	void RequestTransitionOnBlocks(EUIKitBlockVisualState State);

	UFUNCTION(BlueprintCallable)
	void SetBlocksTiming(const FUIKitBlockTiming& Timing);

	UFUNCTION(BlueprintCallable)
	void UnregisterAllModularBlocks();

	UFUNCTION(BlueprintCallable)
	void UnregisterModularBlock(UUIKitBlock* Block);

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="UIKitModularButton", meta=(EditInline="true"))
	TArray<TObjectPtr<UUIKitBlock>> ModularBlocks;

};

