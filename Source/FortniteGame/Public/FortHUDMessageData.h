// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "Athena/AthenaGameMessage.h"
#include "FortHUDMessageData.generated.h"

class APlayerState;

UENUM(BlueprintType)
enum class EHUDMessagePlacement : uint8
{
	// Invalid

	None = 0,
	// Bottom vertically, center horizontally

	BottomCenter = 1,
	// Top vertically, center horizontally

	TopCenter = 2,
	// Center vertically, right horizontally

	CenterRight = 3,
};

USTRUCT(BlueprintType)
struct FHUDMessageData : public FAthenaGameMessageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HUDMessageData")
	EHUDMessagePlacement Placement;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUDMessageData")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HUDMessageData")
	int32 MessageTargets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HUDMessageData")
	ETextTransformPolicy TextTransformPolicy;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUDMessageData")
	int32 DisableChannel;

};

