// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricModulatable.h"
#include "FabricTextureProvider.h"
#include "FabricTextureModifier.generated.h"

class UTexture;

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricTextureModifierBase : public UFabricModulatable
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSourceTextureChanged, const TArray<FFabricTextureProviderTexture>&, Textures);

public:
	UPROPERTY(BlueprintAssignable)
	FOnSourceTextureChanged OnSourceTexturesChanged;

protected:
	UPROPERTY(BlueprintReadWrite, Category="FabricTextureModifierBase")
	TObjectPtr<UTexture> ModifiedTexture;

};

