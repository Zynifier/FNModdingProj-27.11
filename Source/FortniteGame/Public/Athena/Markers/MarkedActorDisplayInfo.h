// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Math/Color.h"
#include "MarkedActorDisplayInfo.generated.h"

class UMarkedActorDisplayInfoAdditionalData;
class USoundBase;
class UTexture2D;
class UUserWidget;

UENUM()
enum class EFortMarkedActorScreenClamping : uint8
{
	Default = 0,
	Clamp = 1,
	ClampWhileNew = 2,
	DontClamp = 3,
};

USTRUCT(BlueprintType)
struct FMarkedActorDisplayInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MarkedActorDisplayInfo")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MarkedActorDisplayInfo")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MarkedActorDisplayInfo")
	TSoftClassPtr<UUserWidget> CustomIndicatorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MarkedActorDisplayInfo")
	TSoftClassPtr<UUserWidget> CustomDetailsClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MarkedActorDisplayInfo")
	FLinearColor PrimaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MarkedActorDisplayInfo")
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MarkedActorDisplayInfo")
	EFortMarkedActorScreenClamping ScreenClamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MarkedActorDisplayInfo")
	float CustomTimeToLive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MarkedActorDisplayInfo")
	TObjectPtr<UMarkedActorDisplayInfoAdditionalData> AdditionalData;

};

