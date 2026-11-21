// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ApolloIntroShimBase.generated.h"

UCLASS(Abstract)
class UApolloIntroShimBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UApolloIntroShimBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

