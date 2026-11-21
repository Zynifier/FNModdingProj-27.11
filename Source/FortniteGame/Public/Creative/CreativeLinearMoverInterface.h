// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreativeLinearMoverInterface.generated.h"

UINTERFACE()
class UCreativeLinearMoverInterface : public UInterface
{
	GENERATED_BODY()
};

class ICreativeLinearMoverInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool IsTargetableByLinearMover() const;

	UFUNCTION(BlueprintNativeEvent)
	bool ShouldInvisiblePropsBeAllowed() const;

};

