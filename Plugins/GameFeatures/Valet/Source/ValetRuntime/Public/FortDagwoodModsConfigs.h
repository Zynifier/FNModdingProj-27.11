// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortDagwoodModsConfigs.generated.h"

class USkeletalMesh;

USTRUCT(BlueprintType)
struct FVehicleAttachment
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleAttachment")
	FName ModName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleAttachment")
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleAttachment")
	TObjectPtr<USkeletalMesh> SkeletalMesh;

};

UCLASS(Config=Game, BlueprintType, Blueprintable)
class UFortDagwoodModsConfigs : public UObject
{
	GENERATED_BODY()

};

