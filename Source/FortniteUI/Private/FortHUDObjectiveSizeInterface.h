// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDObjectiveSizeInterface.generated.h"

class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSizeEstimateChanged, UObject*, ChangedElement);

UINTERFACE(BlueprintType, Blueprintable)
class UFortHUDObjectiveSizeInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortHUDObjectiveSizeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetHeightEstimate() const;

};

