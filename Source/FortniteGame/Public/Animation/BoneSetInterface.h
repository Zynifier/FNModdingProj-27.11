// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/BoneReference.h"
#include "BoneSetInterface.generated.h"

USTRUCT()
struct FBoneSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BoneSet")
	TArray<FBoneReference> Bones;

	UPROPERTY(EditAnywhere, Category="BoneSet")
	TArray<FName> Sockets;

};

UINTERFACE(MinimalAPI)
class UBoneSetInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IBoneSetInterface
{
	GENERATED_BODY()

};

