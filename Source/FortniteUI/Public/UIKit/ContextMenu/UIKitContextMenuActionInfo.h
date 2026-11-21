// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIKitContextMenuActionInfo.generated.h"

class UTexture2D;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FOnContextMenuInteractionDelegate);

USTRUCT(BlueprintType)
struct FUIKitContextMenuActionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitContextMenuActionInfo")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitContextMenuActionInfo", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UTexture2D> IconTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitContextMenuActionInfo")
	int32 SortPriority;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIKitContextMenuActionInfo")
	bool bIsAvailable;

	UPROPERTY()
	FOnContextMenuInteractionDelegate InteractionDelegate;

};

