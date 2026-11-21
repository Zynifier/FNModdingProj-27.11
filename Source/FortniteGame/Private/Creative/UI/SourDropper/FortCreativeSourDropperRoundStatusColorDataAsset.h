// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "FortTeamEnum.h"
#include "FortCreativeSourDropperRoundStatusColorDataAsset.generated.h"

UENUM(BlueprintType)
enum class EFortSourDropperColorType : uint8
{
	None = 0,
	Bright = 1,
	MidBright = 2,
	MidDark = 3,
	Dark = 4,
};

USTRUCT(BlueprintType)
struct FFortSourDropperColorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSourDropperColorData")
	TMap<EFortSourDropperColorType, FLinearColor> TypeColors;

};

UCLASS(BlueprintType, Blueprintable)
class UFortCreativeSourDropperRoundStatusColorDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeSourDropperRoundStatusColorDataAsset")
	TMap<TEnumAsByte<EFortTeamAffiliation::Type>, FFortSourDropperColorData> AffiliationColors;

};

