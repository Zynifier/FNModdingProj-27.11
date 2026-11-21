// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Core/FortSpatialGrid.h"
#include "CurieManagerComponent.h"
#include "FortCurieElementNavRelevantSpatialGrid.generated.h"

class UFortCurieDangerousNavRelevantObject;

USTRUCT()
struct FFortCurieNavRelevantSpatialGrid : public FFortSpatialGrid
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FIntPoint, TObjectPtr<UFortCurieDangerousNavRelevantObject>> NavRelevantObjectMap;

	UPROPERTY()
	TArray<TObjectPtr<UFortCurieDangerousNavRelevantObject>> NavRelevantPool;

};

UINTERFACE()
class FORTNITEGAME_API UFortCurieNavRelevantSpatialGridInterface : public UCurieManagerComponentInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortCurieNavRelevantSpatialGridInterface : public ICurieManagerComponentInterface
{
	GENERATED_BODY()

};

