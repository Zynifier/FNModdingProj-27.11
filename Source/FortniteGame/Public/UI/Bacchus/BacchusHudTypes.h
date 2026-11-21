// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BacchusHudTypes.generated.h"

class UPaperSprite;

UENUM(BlueprintType)
enum class EBacchusHUDStateType : uint8
{
	DoNothing = 0,
	Hide = 1,
	Show = 2,
	FallbackToDefault = 3,
};

USTRUCT(BlueprintType)
struct FBacchusActionIconMapping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BacchusActionIconMapping")
	FName Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BacchusActionIconMapping")
	TObjectPtr<UPaperSprite> Sprite;

};

