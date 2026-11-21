// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetUserData.h"
#include "Math/MathFwd.h"
#include "FortStaticMeshUserData.generated.h"

class UNavLinkDefinition;

USTRUCT()
struct FTransformableNavLinkClass
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Default", meta=(MakeEditWidget))
	FVector Translation;

	UPROPERTY(EditAnywhere, Category="Default", meta=(MakeEditWidget))
	FRotator Rotation;

	UPROPERTY(EditAnywhere, Category="Default")
	TSubclassOf<UNavLinkDefinition> NavigationLinksClass;

};

UCLASS(MinimalAPI)
class UFortStaticMeshUserData : public UAssetUserData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Navigation")
	TArray<FTransformableNavLinkClass> NavLinks;

};

