// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "FortWeaponModData.generated.h"

class UAnimMontage;
class UAnimSequence;
class UFortWeaponModAudioData;
class UMetaSoundPatch;
class USoundLibrary;
class UStaticMesh;

USTRUCT()
struct FWeaponModAnimData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAnimSequence> LeftHandPoseOffset;

	UPROPERTY()
	TObjectPtr<UAnimMontage> PlayerReloadAnimMontage;

	UPROPERTY()
	TObjectPtr<UAnimMontage> WeaponReloadAnimMontage;

};

USTRUCT(BlueprintType)
struct FWeaponModStaticMeshData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WeaponModStaticMeshData")
	TObjectPtr<UStaticMesh> ModMesh;

	UPROPERTY(EditDefaultsOnly, Category="WeaponModStaticMeshData")
	FName SocketName;

	UPROPERTY(EditDefaultsOnly, Category="WeaponModStaticMeshData")
	FTransform RelativeTransform;

};

USTRUCT(BlueprintType)
struct FWeaponModCosmeticData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WeaponModCosmeticData")
	FWeaponModStaticMeshData MeshData;

	UPROPERTY(EditDefaultsOnly, Category="WeaponModCosmeticData")
	TObjectPtr<UFortWeaponModAudioData> AudioData;

};

USTRUCT(BlueprintType)
struct FWeaponModReloadAnimData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WeaponModReloadAnimData")
	TObjectPtr<UAnimMontage> PlayerReloadAnim;

	UPROPERTY(EditDefaultsOnly, Category="WeaponModReloadAnimData")
	TObjectPtr<UAnimMontage> WeaponReloadAnim;

};

UCLASS(BlueprintType)
class UFortWeaponModAudioData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sounds")
	TArray<TObjectPtr<USoundLibrary>> SoundLibraries;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sounds")
	TObjectPtr<UMetaSoundPatch> MetaSoundPatch1P;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sounds")
	TObjectPtr<UMetaSoundPatch> MetaSoundPatch3P;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sounds")
	int32 SortOrder;

};

