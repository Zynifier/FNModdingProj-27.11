// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "GGWidgetBase.generated.h"

class AFortAthenaMutator_GG;
class UWorld;

UCLASS()
class UGGWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="GGWidgetBase")
	TObjectPtr<AFortAthenaMutator_GG> BaseMutator;

private:
	UPROPERTY()
	TWeakObjectPtr<UWorld> CachedWorld;

};

