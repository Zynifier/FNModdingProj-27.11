// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaCollectionOverlayEntry.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionOverlayEntry : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Display Name Set"))
	void BP_OnDisplayNameSet(const FString& DisplayName);

protected:
	UPROPERTY(EditAnywhere, Category="Text")
	FText EmptyDisplayNameText;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionOverlayEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DisplayName;

};

