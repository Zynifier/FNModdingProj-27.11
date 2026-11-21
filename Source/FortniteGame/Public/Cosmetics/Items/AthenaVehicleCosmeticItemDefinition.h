// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaVehicleCosmeticItemDefinition.generated.h"

class UStaticMesh;

UENUM(BlueprintType)
enum class EFortVehicleDecoType : uint8
{
	Unknown = 0,
	Flag = 1,
	HoodOrnament = 2,
	Wings = 3,
};

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaVehicleCosmeticItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaVehicleCosmeticItemDefinition")
	EFortVehicleDecoType DecoType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaVehicleCosmeticItemDefinition")
	FTransform DecoSocketTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaVehicleCosmeticItemDefinition")
	TSoftObjectPtr<UStaticMesh> TestDecoMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaVehicleCosmeticItemDefinition")
	FName DecoSocketName;

};

