// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Math/MathFwd.h"
#include "FortAnimNotifyState_SpawnEmoteEmitter.generated.h"

class UParticleSystem;
class UParticleSystemComponent;

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_SpawnEmoteEmitter : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify")
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify")
	FVector LocationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify")
	FRotator RotationOffset;

	UPROPERTY(EditAnywhere, Category="AnimNotify")
	FVector Scale;

	UPROPERTY(EditAnywhere, Category="AnimNotify")
	TObjectPtr<UParticleSystem> EmitterTemplate;

	UPROPERTY(EditAnywhere, Category="AnimNotify")
	int32 EmitterId;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<int32, TObjectPtr<UParticleSystemComponent>> PreviewEmoteParticleSystemComps;
#endif

};

