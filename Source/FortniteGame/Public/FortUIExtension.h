// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUIExtensionSlot.h"
#include "FortUIExtension.generated.h"

class UUserWidget;

USTRUCT(BlueprintType)
struct FUIExtension
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIExtension")
	EUIExtensionSlot Slot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIExtension")
	TSoftClassPtr<UUserWidget> WidgetClass;


	FORTNITEGAME_API bool operator==(const FUIExtension& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FUIExtension& Value);
};

